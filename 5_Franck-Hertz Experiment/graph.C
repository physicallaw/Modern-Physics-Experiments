{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   FILE *f;
   f=fopen("3.csv", "r");

   int n1 = 266;
   double x[n1], y[n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf, %lf ", &x[i], &y[i]);
//      printf("%lf %lf\n", x[i], y[i]);
   }
      // create first graph

   TGraph *gr1 = new TGraph(n1,x,y);
   gr1->SetTitle("Franck-Hertz experiment with neon");
   gr1->GetXaxis()->SetTitle("U_{B1}(V)");
   gr1->GetYaxis()->SetTitle("U_{A1}(V)");
   gr1->SetLineColor(1);
   gr1->SetLineWidth(1);
//   gr1->GetXaxis()->SetRangeUser(0,25);
   gr1->Draw();

   c1->Update();
   c1->Modified();
   return c1;
}
