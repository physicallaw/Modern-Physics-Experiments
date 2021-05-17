{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",700,500);

   FILE *f;
   f=fopen("3.csv", "r");

   int n1 = 48;
   double x[n1], y[7][n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &x[i], &y[0][i], &y[1][i], &y[2][i], &y[3][i], &y[4][i], &y[5][i], &y[6][i]);
//      printf("%lf %lf\n", x[i], y[5][i]);
   }
      // create first graph
   TGraph gr[7];

   for(int i=0; i<7; i++){
   gr[i] = new TGraph(n1,x,y[i]);
   gr[i]->SetTitle("Duane-Hunt relation and Planck's constant");
   gr[i]->GetXaxis()->SetTitle("n#lambda(pm)");
   gr[i]->GetYaxis()->SetTitle("R(1/s)");
   gr[i]->SetLineColor(1);
   gr[i]->SetLineWidth(1);
   gr[i]->GetXaxis()->SetRangeUser(0,60);
   }
   gr[6]->Draw();
   gr[5]->Draw("L");
   gr[4]->Draw("L");
   gr[3]->Draw("L");
   gr[2]->Draw("L");
   gr[1]->Draw("L");
   gr[0]->Draw("L");

   TLine line[10];
   double t = gr[6]->GetYaxis()->GetXmax();
   line[0] = new TLine(23.3,0,(t+34*23.3)/34*1.2,t);
   line[1] = new TLine(24.9,0,(t+32*24.9)/32*1.3,t);
   line[2] = new TLine(27.8,0,(t+30*27.8)/30*1.4,t);
   line[3] = new TLine(30.0,0,(t+28*30.0)/28*1.5,t);
   line[4] = new TLine(33.0,0,(t+26*33.0)/26*1.6,t);
   line[5] = new TLine(36.5,0,(t+24*36.5)/24*1.7,t);
   line[6] = new TLine(40.6,0,(t+22*40.6)/22*1.8,t);

   for (int i=0; i<10; i++){
//      line[i]->SetLineColor(kGray+1);
      line[i]->Draw();
   }

   c1->Update();
   c1->Modified();
   return c1;
}
