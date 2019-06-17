#ifndef CODE_ParametersSolo
#define CODE_ParametersSolo
#include "IncludeDefine.h"

class Parameters;

class ParametersSolo {
public:
    //chemistry, library etc
    string typeStr;
    int type;
    uint32 cbS,cbL; //cell barcode start,length
    uint32 umiS,umiL; //umi start,length
    uint32 bL; //total barcode length
    string soloCBwhitelist;
    std::vector <uint64> cbWL;
    bool cbWLyes;
    string strandStr;
    int32 strand;
    //features
    const static vector<string> featureNames;
    vector<string> featureIn;
    vector<uint32> features, featureInd;
    uint32 nFeatures;
    bool *featureYes; //which features are requested
    //filtering
    char QSbase,QSmax;//quality score base and cutoff
    float cbMinP;//for CBs with non-exact matching to WL, min posterior probability
    //algorithms
    vector <string> umiDedup;
    vector <uint32> umiDedupColumns;
    vector <bool> umiDedupYes;
    //output
    vector<string> outFileNames;
    //constants
    uint32 umiMaskLow, umiMaskHigh; //low/high half bit-mask or UMIs
    
    bool samAttrYes;//post-processed SAM attributes: error-corrected CB and UMI
    int32 samAttrFeature;//which feature to use for error correction

    void initialize(Parameters *pPin);
    void umiSwapHalves(uint32 &umi);
private:
    Parameters *pP;
};
#endif
