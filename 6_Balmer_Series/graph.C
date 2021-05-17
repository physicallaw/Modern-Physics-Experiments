{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   int n1 = 3;
   double x[] = {0.138889, 0.1875, 0.21},
	  y[] = {4.43938E14,6.02265E14,6.60784E14};

   TGraph *gr1 = new TGraph(n1,x,y);
   gr1->SetTitle("Balmer series for H_{2}");
   gr1->GetXaxis()->SetTitle("1/2^{2}-1/n^{2}");
   gr1->GetYaxis()->SetTitle("f(Hz)");
   gr1->SetMarkerStyle(20);
   gr1->SetLineColor(1);
   gr1->SetLineWidth(1);
   gr1->GetXaxis()->SetLimits(0,0.25);
   gr1->GetXaxis()->SetRangeUser(0,0.25);
   gr1->GetYaxis()->SetLimits(0,7E14);
   gr1->GetYaxis()->SetRangeUser(0,7E14);
   TF1 *f1 = new TF1("f1", "[0]*x+[1]",0.12,0.22);
   f1->SetLineColor(kGray+2);
   gr1->Fit("f1");
   gr1->Draw("AP");

   c1->Update();
   c1->Modified();
   return c1;
}
