{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Current vs. Hall voltage(n-type Ge)",700,500);
   c1->SetGrid();

      // draw a frame to define the range
   TMultiGraph *mg = new TMultiGraph();
   mg->SetTitle("Magnetic field vs. Hall voltage (n-type Ge); Magnetic field(mT); Voltage(V)");

      // create first graph
   const Int_t n1 = 46;
   Double_t px1[] = {
0,4,12,16.5,22,24,32.5,35.5,39.5,47,49.5,56.5,62,69.5,73,77.5,81.5,88,91.5,98.5,107.5,115.5,118,126,128.5,134,135.5,140.5,143,146,155,155.5,161.5,173.5,180.5,186,188.5,192.5,194.5,196.5,202,215,220.5,224,227,231.5
};
   Double_t py1[] = {
-0.0005,0,0,0,0.0005,0.0005,0.001 ,0.0015,0.0015,0.002 ,0.0025,0.0025,0.003 ,0.0035,0.0035,0.004 ,0.004 ,0.0045,0.005 ,0.0055,0.006 ,0.006 ,0.0065,0.0065,0.007 ,0.0075,0.0075,0.0075,0.008 ,0.008 ,0.0085,0.0085,0.0085,0.0095,0.01  ,0.0105,0.0105,0.011 ,0.011 ,0.011 ,0.0115,0.012 ,0.0125,0.0125,0.0125,0.013 
};
   TGraph *gr1 = new TGraphErrors(n1,px1,py1);
   gr1->SetMarkerColor(kGray+1);
   gr1->SetMarkerStyle(21);
   TF1 *f1 = new TF1("f1", "[0]+[1]*x",0,30);
   f1->SetLineColor(kGray+1);
   gr1->Fit("f1");
   mg->Add(gr1);

      // create second graph
   const Int_t n2 = 45;
   Float_t x2[]  = {
0,4.5,8,13.5,17,21,24,28,33.5,36.5,41,44.5,50,56.5,71,80.5,85.5,88.5,94.5,97.5,102.5,105,113,114.5,120.5,125.5,133,143.5,146.5,155.5,164.5,170,175.5,180.5,189,193.5,197.5,202,205.5,211,216,224,225,229,232.5
};
   Float_t y2[]  = {
0,0.0005,0.001 ,0.0015,0.002 ,0.0025,0.0035,0.0035,0.004 ,0.005 ,0.005 ,0.0055,0.0065,0.0075,0.0095,0.01  ,0.011 ,0.011 ,0.012 ,0.0125,0.013 ,0.013 ,0.014 ,0.0145,0.015 ,0.0155,0.0165,0.0175,0.0185,0.0185,0.0205,0.021 ,0.0215,0.0225,0.0235,0.024 ,0.0245,0.025 ,0.0255,0.026 ,0.0265,0.0275,0.0275,0.028 ,0.0285
};
   TGraph *gr2 = new TGraphErrors(n2,x2,y2);
   gr2->SetMarkerColor(kGray+2);
   gr2->SetMarkerStyle(20);
   TF1 *f2 = new TF1("f2", "[0]+[1]*x",0,3);
   f2->SetLineColor(kGray+2);
   gr2->Fit("f2");
   mg->Add(gr2);

      // create third graph
   const Int_t n3 = 51;
   Float_t x3[]  = {
0,50.5,52,56,60.5,60,60.5,10,13.5,17.5,22,27,30.5,34,40,44,50.5,70.5,75.5,79.5,85,92.5,98.5,106.5,114,119.5,126,132,155,165,170.5,175,176.5,179.5,180.5,182.5,189.5,193,197.5,201,207,207.5,215.5,219,219,229,235,236.5,241,242,242
};
   Float_t y3[]  = {
0.0015,0.014 ,0.014 ,0.015 ,0.0165,0.0165,0.0165,0.004 ,0.005 ,0.006 ,0.007 ,0.008 ,0.009 ,0.01  ,0.011 ,0.0125,0.014 ,0.0185,0.02  ,0.021 ,0.0225,0.024 ,0.0255,0.0275,0.029 ,0.0305,0.032 ,0.033 ,0.0385,0.0405,0.042 ,0.043 ,0.0435,0.044 ,0.0445,0.045 ,0.046 ,0.047 ,0.048 ,0.0485,0.05  ,0.0505,0.0515,0.0525,0.053 ,0.0545,0.056 ,0.0565,0.0575,0.0575,0.058
};
   TGraph *gr3 = new TGraphErrors(n3,x3,y3);
   gr3->SetMarkerColor(kBlack);
   gr3->SetMarkerStyle(22);
   TF1 *f3 = new TF1("f3", "[0]+[1]*x",0,25);
   f3->SetLineColor(kBlack);
   gr3->Fit("f3");
   mg->Add(gr3);

   mg->Draw("ap");

     //force drawing of canvas to generate the fit TPaveStats
   c1->Update();
   TPaveStats *stats1 = (TPaveStats*)gr1->GetListOfFunctions()->FindObject("stats");
   TPaveStats *stats2 = (TPaveStats*)gr2->GetListOfFunctions()->FindObject("stats");
   TPaveStats *stats3 = (TPaveStats*)gr3->GetListOfFunctions()->FindObject("stats");
   c1->Modified();
   return c1;
}
