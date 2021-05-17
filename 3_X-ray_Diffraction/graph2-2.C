{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   FILE *f;
   f=fopen("2-2.csv", "r");

   int n1 = 106;
   double x[n1], y[4][n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf, %lf, %lf, %lf, %lf ", &x[i], &y[0][i], &y[1][i], &y[2][i], &y[3][i]);
//      printf("%lf %lf\n", x[i], y[i]);
   }
      // create first graph
   TGraph gr[4];

   for(int i=0; i<4; i++){
   gr[i] = new TGraph(n1,x,y[i]);
   gr[i]->SetTitle("Energy spectrum of an X-ray (vs. current)");
   gr[i]->GetXaxis()->SetTitle("n#lambda(pm)");
   gr[i]->GetYaxis()->SetTitle("R(1/s)");
   gr[i]->SetLineColor(1);
   gr[i]->SetLineWidth(1);
   gr[i]->GetXaxis()->SetRangeUser(0,125);
   }
   gr[3]->Draw();
   gr[2]->Draw("L");
   gr[1]->Draw("L");
   gr[0]->Draw("L");

   TLine line[10];
   line[0] = new TLine(61.91,0,61.91,gr[3]->GetYaxis()->GetXmax());
   line[1] = new TLine(54.71,0,54.71,gr[3]->GetYaxis()->GetXmax());
   line[2] = new TLine(62.68,0,62.68,gr[3]->GetYaxis()->GetXmax());
   line[3] = new TLine(54.78,0,54.78,gr[3]->GetYaxis()->GetXmax());
   line[4] = new TLine(62.68,0,62.68,gr[3]->GetYaxis()->GetXmax());
   line[5] = new TLine(54.67,0,54.67,gr[3]->GetYaxis()->GetXmax());
   line[6] = new TLine(62.72,0,62.72,gr[3]->GetYaxis()->GetXmax());
   line[7] = new TLine(54.66,0,54.66,gr[3]->GetYaxis()->GetXmax());

   for (int i=0; i<8; i++){
//      line[i]->SetLineColor(kGray+1);
      line[i]->Draw();
   }


   c1->Update();
   c1->Modified();
   return c1;
}
