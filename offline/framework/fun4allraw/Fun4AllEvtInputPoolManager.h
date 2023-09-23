// Tell emacs that this is a C++ source
//  -*- C++ -*-.
#ifndef FUN4ALLRAW_FUN4ALLEVTINPUTPOOLMANAGER_H
#define FUN4ALLRAW_FUN4ALLEVTINPUTPOOLMANAGER_H

#include <fun4all/Fun4AllInputManager.h>

#include <Event/phenixTypes.h>

#include <map>
#include <string>

class SingleStreamingInput;
class ospEvent;
class InttRawHit;
class Packet;
class PHCompositeNode;
class SyncObject;
class TpcRawHit;

class Fun4AllEvtInputPoolManager : public Fun4AllInputManager
{
 public:
  Fun4AllEvtInputPoolManager(const std::string &name = "DUMMY", const std::string &evtnodename = "EVT", const std::string &topnodename = "TOP");
  ~Fun4AllEvtInputPoolManager() override;
  int fileopen(const std::string &filenam) override { return 0; }
  // cppcheck-suppress virtualCallInConstructor
  int fileclose() override;
  int run(const int nevents = 0) override;

  void Print(const std::string &what = "ALL") const override;
  int ResetEvent() override;
  int PushBackEvents(const int i) override;
  int GetSyncObject(SyncObject **mastersync) override;
  int SyncIt(const SyncObject *mastersync) override;
  int HasSyncObject() const override { return 1; }
  std::string GetString(const std::string &what) const override;
//  SingleEvtInput *AddEvtInputList(const std::string &listfile);
//  SingleEvtInput *AddEvtInputFile(const std::string &filename);
  void registerStreamingInput(SingleStreamingInput *evtin);
  void AddPacket(uint64_t bclk, Packet *p);
  void UpdateEventFoundCounter(const int evtno);
  void AddInttRawHit(uint64_t bclk, InttRawHit *hit);
  void AddTpcRawHit(uint64_t bclk, TpcRawHit *hit);

 private:
  struct PacketInfo
  {
    std::vector<Packet *> PacketVector;
    unsigned int EventFoundCounter = 0;
  };
  struct InttRawHitInfo
  {
    std::vector<InttRawHit *> InttRawHitVector;
    unsigned int EventFoundCounter = 0;
  };

  struct TpcRawHitInfo
  {
    std::vector<TpcRawHit *> TpcRawHitVector;
    unsigned int EventFoundCounter = 0;
  };

  int m_RunNumber = 0;
  std::vector<SingleStreamingInput *> m_EvtInputVector;
  SyncObject *m_SyncObject = nullptr;
  PHCompositeNode *m_topNode = nullptr;
  std::map<uint64_t, PacketInfo> m_PacketInfoMap;
  std::map<uint64_t, InttRawHitInfo> m_InttRawHitMap;
  std::map<uint64_t, TpcRawHitInfo> m_TpcRawHitMap;
  std::string m_EvtNodeName;
};

#endif /* FUN4ALL_FUN4ALLEVTINPUTPOOLMANAGER_H */
