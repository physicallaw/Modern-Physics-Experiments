{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   FILE *f;
   f=fopen("2-1.csv", "r");

   int n1 = 106;
   double x[n1], y[5][n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf, %lf, %lf, %lf, %lf, %lf ", &x[i], &y[0][i], &y[1][i], &y[2][i], &y[3][i], &y[4][i]);
//      printf("%lf %lf\n", x[i], y[i]);
   }
      // create first graph
   TGraph gr[5];

   for(int i=0; i<5; i++){
   gr[i] = new TGraph(n1,x,y[i]);
   gr[i]->SetTitle("Energy spectrum of an X-ray (vs. high voltage)");
   gr[i]->GetXaxis()->SetTitle("n#lambda(pm)");
   gr[i]->GetYaxis()->SetTitle("R(1/s)");
   gr[i]->SetLineColor(1);
   gr[i]->SetLineWidth(1);
   gr[i]->GetXaxis()->SetRangeUser(0,125);
   }
   gr[4]->Draw();
   gr[3]->Draw("L");
   gr[2]->Draw("L");
   gr[1]->Draw("L");
   gr[0]->Draw("L");

   TLine line[10];
   line[0] = new TLine(74.18,0,74.18,gr[4]->GetYaxis()->GetXmax());
   line[1] = new TLine(70.69,0,70.69,gr[4]->GetYaxis()->GetXmax());
   line[2] = new TLine(62.55,0,62.55,gr[4]->GetYaxis()->GetXmax());
   line[3] = new TLine(59.21,0,59.21,gr[4]->GetYaxis()->GetXmax());
   line[4] = new TLine(62.38,0,62.38,gr[4]->GetYaxis()->GetXmax());
   line[5] = new TLine(55.42,0,55.42,gr[4]->GetYaxis()->GetXmax());
   line[6] = new TLine(62.64,0,62.64,gr[4]->GetYaxis()->GetXmax());
   line[7] = new TLine(54.88,0,54.88,gr[4]->GetYaxis()->GetXmax());
   line[8] = new TLine(62.94,0,62.94,gr[4]->GetYaxis()->GetXmax());
   line[9] = new TLine(54.84,0,54.84,gr[4]->GetYaxis()->GetXmax());

   for (int i=0; i<10; i++){
//      line[i]->SetLineColor(kGray+1);
      line[i]->Draw();
   }


   c1->Update();
   c1->Modified();
   return c1;
}
