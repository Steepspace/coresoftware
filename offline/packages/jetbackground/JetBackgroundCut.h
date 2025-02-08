#ifndef JETBACKGROUNDCUT_H
#define JETBACKGROUNDCUT_H

#include <fun4all/SubsysReco.h>
#include <string>
#include <cmath>
#include <phool/recoConsts.h>
#include <globalvertex/GlobalVertex.h>
class PHCompositeNode;
class CentralityInfo;
class JetBackgroundCut : public SubsysReco
{
 public:

  JetBackgroundCut(const std::string jetNodeName, const std::string &name = "JetBackgroundCutModule", const int debug = 0, const bool doAbort = 0, GlobalVertex::VTXTYPE vtxtype = GlobalVertex::MBD, int sysvar = 0);

  virtual ~JetBackgroundCut();

  bool failsLoEmFracETCut(float emFrac, float ET, bool dPhiCut, bool isDijet)
  {
    float widen = 0;
    float shift = 0;
    if(_sysvar > 0)
      {
	widen = 0.05;
	shift = -2.5;
      }
    else if(_sysvar < 0)
      {
	widen = -0.05;
	shift = 2.5;
      }
    return (emFrac < (0.1+widen) && ET > (50*emFrac+20+shift)) && (dPhiCut || !isDijet);
  }

  bool failsHiEmFracETCut(float emFrac, float ET, bool dPhiCut, bool isDijet)
  {
    float widen = 0;
    float shift = 0;
    if(_sysvar > 0)
      {
	widen = -0.05;
	shift = -2.5;
      }
    else if(_sysvar < 0)
      {
	widen = 0.05;
	shift = 2.5;
      }
    return (emFrac > (0.9+widen) && ET > (-50*emFrac+70+shift)) && (dPhiCut || !isDijet);
  }

  bool failsIhFracCut(float emFrac, float ohFrac)
  {
    float shift = 0;
    if(_sysvar > 0)
      {
	shift = 0.05;
      }
    else if(_sysvar < 0)
      {
	shift = -0.05;
      }
    return emFrac + ohFrac < 0.65+shift;
  }

  bool failsdPhiCut(float dPhi, bool isDijet)
  {
    return dPhi < 3*M_PI/4 && isDijet;
  }

  int Init(PHCompositeNode *topNode) override;

  int process_event(PHCompositeNode *topNode) override;

  int ResetEvent(PHCompositeNode *topNode) override;

  int End(PHCompositeNode *topNode) override;

  int Reset(PHCompositeNode * /*topNode*/) override;

  void Print(const std::string &what = "ALL") const override;


 private:
  recoConsts *_rc;
  bool _doAbort;
  std::string _name;
  int _debug;
  bool _missingInfoWarningPrinted = false;
  std::string _jetNodeName;
  GlobalVertex::VTXTYPE _vtxtype;
  int _sysvar;
};

#endif // R24TREEMAKER
