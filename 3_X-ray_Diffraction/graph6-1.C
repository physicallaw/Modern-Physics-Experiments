{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   FILE *f;
   f=fopen("6-1.csv", "r");

   int n1 = 69;
   double x[n1], y[4][n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf,%lf,%lf,%lf,%lf", &x[i], &y[0][i], &y[1][i], &y[2][i], &y[3][i]);
//      printf("%lf %lf\n", x[i], y[5][i]);
   }
      // create first graph
   TGraph gr[4];

   for(int i=0; i<4; i++){
   gr[i] = new TGraph(n1,x,y[i]);
   gr[i]->SetTitle("Moseley’s law and Rydberg constant");
   gr[i]->GetXaxis()->SetTitle("n#lambda(pm)");
   gr[i]->GetYaxis()->SetTitle("R(1/s)");
   gr[i]->SetLineColor(1);
   gr[i]->SetLineWidth(1);
   gr[i]->GetXaxis()->SetRangeUser(0,80);
   }
   gr[0]->Draw();
   gr[3]->Draw("L");
   gr[2]->Draw("L");
   gr[1]->Draw("L");

   c1->Update();
   c1->Modified();
   return c1;
}
