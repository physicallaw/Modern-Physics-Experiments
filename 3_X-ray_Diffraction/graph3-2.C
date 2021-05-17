{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   double x[] = {1./34,1./32,1./30,1./28,1./26,1./24,1./22};
   double y[] = {23.3,24.9,27.8,30.0,33.0,36.5,40.6};

   TGraph *gr = new TGraph(6,x,y);
   gr->SetTitle("Duane-Hunt relation and Planck's constant");
   gr->GetXaxis()->SetTitle("1/U(1/kV)");
   gr->GetYaxis()->SetTitle("#lambda_{min}(pm)");
   gr->SetLineColor(1);
   gr->SetLineWidth(2);
   gr->GetXaxis()->SetRangeUser(0,0.05);
   gr->GetXaxis()->SetLimits(0,0.05);
   gr->GetYaxis()->SetRangeUser(0,45);
   gr->GetYaxis()->SetLimits(0,45);
   gr->Draw();

   double t = 45;
   TLine *line = new TLine(8.6/1083,0,(t+8.6)/1083,t);
   line->SetLineColor(kGray+1);
   line->Draw();

   c1->Update();
   c1->Modified();
   return c1;
}
