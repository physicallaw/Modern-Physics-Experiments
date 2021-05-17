{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",1400,500);
   c1.Divide(2,1);

      // draw a frame to define the range
   TMultiGraph *mg = new TMultiGraph();
   mg->SetTitle("Ferromagnetic Hysteresis; Current(A); Voltage(V)");

   FILE *f;
   f=fopen("exp6.csv", "r");

   int n1 = 4184;
   double t[n1], phi[n1], current[n1], v[n1], r[n1], s[n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf, %lf, %lf, %lf, %lf, %lf ", &t[i], &phi[i], &current[i], &v[i], &r[i], &s[i]);
      //printf("%f, %f,", phi[i], current[i]);
   }
      // create first graph

   double B[n1], H[n1];
   for (int i=0;i<n1;i++){
      B[i]= phi[i]*(-1)/500/0.04/0.04;
      H[i] = current[i]*500/0.15;
   }

   TGraph *gr1 = new TGraph(n1,H,B);
   gr1->SetTitle("Ferromagnetic Hysteresis at 2V, 0.13Hz");
   gr1->GetXaxis()->SetTitle("H(Am^{-1})");
   gr1->GetYaxis()->SetTitle("B(T)");
   gr1->SetLineColor(1);
   gr1->SetLineWidth(1);
   gr1->GetXaxis()->SetRangeUser(-500,500);
   gr1->GetYaxis()->SetRangeUser(-0.5,0.5);
//   TF1 *f1 = new TF1("f1", "[0]+[1]*x",0,30);
//   f1->SetLineColor(kGray+1);
//   gr1->Fit("f1");
   c1.cd(2);
   gr1->Draw();

   double Volt[n1];
   for(int i=0; i<n1; i++)
      Volt[i] = current[i]*22;

   TGraph *gr2 = new TGraph(n1,t,Volt);
   gr2->SetTitle("Voltage-Time at 2V, 0.13Hz");
   gr2->GetXaxis()->SetTitle("t(s)");
   gr2->GetYaxis()->SetTitle("Voltage(V)");
   gr2->SetLineColor(1);
   gr2->SetLineWidth(1);
//   gr2->GetXaxis()->SetRangeUser(-500,500);
//   gr2->GetYaxis()->SetRangeUser(-0.5,0.5);
//   TF1 *f1 = new TF1("f1", "[0]+[1]*x",0,30);
//   f1->SetLineColor(kGray+1);
//   gr1->Fit("f1");
   c1.cd(1);
   gr2->Draw();


   c1->Update();
   c1->Modified();
   return c1;
}
