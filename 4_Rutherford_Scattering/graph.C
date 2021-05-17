{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   int n1 = 18;
   double x[] = {-60,-50,-40,-30,-25,-20,-15,-10,-5,5,10,15,20,25,30,40,50,60},
	  y[] = {0.00565,0.02000,0.03360,0.1800,0.1520,0.952,1.65,3.71,4.87,2.35,1.09,0.325,0.307,0.2276,0.2693,0.1384,0.01375,0.01555};

   TGraph *gr1 = new TGraph(n1,x,y);
   gr1->SetTitle("Rutherford Scattering with gold foil");
   gr1->GetXaxis()->SetTitle("#theta(#circ)");
   gr1->GetYaxis()->SetTitle("R(1/s)");
   gr1->SetMarkerStyle(20);
   gr1->SetLineColor(1);
   gr1->SetLineWidth(1);
//   gr1->GetXaxis()->SetLimits(-180,180);
   gr1->GetXaxis()->SetRangeUser(-180,180);
   TF1 *f1 = new TF1("f1", "[0]/((sin(3.14*(x-[1])/360))^4)",-30,30);
   f1->SetLineColor(kGray+2);
   gr1->Fit("f1");
   gr1->Draw("AP");

   c1->Update();
   c1->Modified();
   return c1;
}
