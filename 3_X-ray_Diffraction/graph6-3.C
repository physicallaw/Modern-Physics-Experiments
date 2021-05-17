{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   double x[] = {40,42,47};
   double y[] = {1/sqrt(57.0),1/sqrt(52.6),1/sqrt(39.8)};

   TGraph *gr = new TGraph(3,x,y);
   gr->SetTitle("Moseley's law and Rydberg constant");
   gr->GetXaxis()->SetTitle("1/#surd#lambda(1/#surdpm)");
   gr->GetYaxis()->SetTitle("Z");
   gr->SetLineColor(1);
   gr->SetLineWidth(2);
   gr->GetXaxis()->SetRangeUser(0,50);
   gr->GetXaxis()->SetLimits(0,50);
   gr->GetYaxis()->SetRangeUser(0,0.175);
   gr->GetYaxis()->SetLimits(0,0.175);
   gr->Draw();

   double t = 0.175;
   TLine *line = new TLine(5.8,0,51.4,t);
   line->SetLineColor(kGray+1);
   line->Draw();

   c1->Update();
   c1->Modified();
   return c1;
}
