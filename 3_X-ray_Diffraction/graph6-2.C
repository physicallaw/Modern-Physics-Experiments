{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   FILE *f;
   f=fopen("6-2.csv", "r");

   int n1 = 69;
   double x[n1], y[3][n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf,%lf,%lf,%lf,%lf", &x[i], &y[0][i], &y[1][i], &y[2][i]);
//      printf("%lf %lf\n", x[i], y[5][i]);
   }
      // create first graph
   TGraph gr[3];

   for(int i=0; i<3; i++){
   gr[i] = new TGraph(n1,x,y[i]);
   gr[i]->SetTitle("Moseley's law and Rydberg constant");
   gr[i]->GetXaxis()->SetTitle("n#lambda(pm)");
   gr[i]->GetYaxis()->SetTitle("T(%)");
   gr[i]->SetLineColor(1);
   gr[i]->SetLineWidth(1);
   gr[i]->GetXaxis()->SetRangeUser(0,80);
   gr[i]->GetXaxis()->SetLimits(0,80);
   }
   gr[0]->Draw();
   gr[2]->Draw("L");
   gr[1]->Draw("L");

   TLine line[3];
   line[0] = new TLine(39.8,0,39.8,gr[0]->GetYaxis()->GetXmax());
   line[1] = new TLine(52.6,0,52.6,gr[0]->GetYaxis()->GetXmax());
   line[2] = new TLine(57.0,0,57.0,gr[0]->GetYaxis()->GetXmax());

   for (int i=0; i<3; i++){
//      line[i]->SetLineColor(kGray+1);
      line[i]->Draw();
   }


   c1->Update();
   c1->Modified();
   return c1;
}
