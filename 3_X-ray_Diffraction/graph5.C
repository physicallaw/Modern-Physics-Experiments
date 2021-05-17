{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   FILE *f;
   f=fopen("5.csv", "r");

   int n1 = 47;
   double x[n1], y[2][n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &x[i], &y[0][i], &y[1][i]);
//      printf("%lf %lf\n", x[i], y[5][i]);
   }
      // create first graph
   TGraph gr[6];

   for(int i=0; i<2; i++){
   gr[i] = new TGraph(n1,x,y[i]);
   gr[i]->SetTitle("Edge absorption : filtering X-rays");
   gr[i]->GetXaxis()->SetTitle("n#lambda(pm)");
   gr[i]->GetYaxis()->SetTitle("R(1/s)");
   gr[i]->SetLineColor(1);
   gr[i]->SetLineWidth(1);
//   gr[i]->GetXaxis()->SetRangeUser(0,60);
   }
   gr[2] = new TGraph(10,&x[21],&y[1][21]);
//   gr[2]->SetFillStyle(3000);
   gr[3] = new TGraph(4,&x[18],&y[1][18]);
   gr[3]->SetFillStyle(3002);
   gr[4] = new TGraph(10,&x[21],&y[0][21]);
   gr[4]->SetFillStyle(3005);
   gr[5] = new TGraph(7,&x[15],&y[0][15]);
   gr[5]->SetFillStyle(3006);

   gr[0]->Draw();
   gr[1]->Draw("L");
   gr[2]->Draw("F");
   gr[3]->Draw("F");
   gr[4]->Draw("F");
   gr[5]->Draw("F");

   c1->Update();
   c1->Modified();
   return c1;
}
