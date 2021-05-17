{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   FILE *f;
   f=fopen("1.csv", "r");

   int n1 = 226;
   double x[n1], y[n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf, %lf ", &x[i], &y[i]);
//      printf("%lf %lf\n", x[i], y[i]);
   }
      // create first graph

   TGraph *gr1 = new TGraph(n1,x,y);
   gr1->SetTitle("Diffraction of X-rays at a single crystal");
   gr1->GetXaxis()->SetTitle("#beta(#circ)");
   gr1->GetYaxis()->SetTitle("R(1/s)");
   gr1->SetLineColor(1);
   gr1->SetLineWidth(1);
   gr1->GetXaxis()->SetRangeUser(0,25);
   gr1->Draw();
   TLine line[6];
   line[0] = new TLine(5.57,0,5.57,gr1->GetYaxis()->GetXmax());
   line[1] = new TLine(6.31,0,6.31,gr1->GetYaxis()->GetXmax());
   line[2] = new TLine(12.08,0,12.08,gr1->GetYaxis()->GetXmax());
   line[3] = new TLine(13.71,0,13.71,gr1->GetYaxis()->GetXmax());
   line[4] = new TLine(18.85,0,18.85,gr1->GetYaxis()->GetXmax());
   line[5] = new TLine(21.38,0,21.38,gr1->GetYaxis()->GetXmax());

   for (int i=0; i<6; i++){
//      line[i]->SetLineColor(kGray+1);
      line[i]->Draw();
   }

   c1->Update();
   c1->Modified();
   return c1;
}
