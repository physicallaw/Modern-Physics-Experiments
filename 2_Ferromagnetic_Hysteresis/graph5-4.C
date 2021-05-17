{
   gStyle->SetOptFit();
   TCanvas *c1 = new TCanvas("c1","Ferromagnetic Hysteresis",1400,500);
   c1.Divide(2,1);
   int bn = 3;

      // draw a frame to define the range
   TMultiGraph *mg = new TMultiGraph();
   mg->SetTitle("Ferromagnetic Hysteresis; Current(A); Voltage(V)");

   FILE *f;
   f=fopen("exp10.csv", "r");

   int n1 = 11929;
   double t[n1], phi[n1], current[n1], v[n1], r[n1], s[n1];
   for (int i=0; i<n1; i++){
      fscanf(f, "%lf, %lf, %lf, %lf, %lf, %lf ", &t[i], &phi[i], &current[i], &v[i], &r[i], &s[i]);
      //printf("%f, %f,", phi[i], current[i]);
   }
      // create first graph

   double B[n1], H[n1];
   double sum1 = 0, sum2 = 0;
   int sw1=0, sw2=0;
   B[0]= phi[0]*(-1)/500/0.04/0.04;
   H[0] = current[0]*500/0.15;
   B[1]= phi[0]*(-1)/500/0.04/0.04;
   H[1] = current[0]*500/0.15;
   B[2]= phi[0]*(-1)/500/0.04/0.04;
   H[2] = current[0]*500/0.15;
   B[3]= phi[0]*(-1)/500/0.04/0.04;
   H[3] = current[0]*500/0.15;
   B[4]= phi[0]*(-1)/500/0.04/0.04;
   H[4] = current[0]*500/0.15;
   B[5]= phi[0]*(-1)/500/0.04/0.04;
   H[5] = current[0]*500/0.15;
   B[6]= phi[0]*(-1)/500/0.04/0.04;
   H[6] = current[0]*500/0.15;
   B[7]= phi[0]*(-1)/500/0.04/0.04;
   H[7] = current[0]*500/0.15;
   B[8]= phi[0]*(-1)/500/0.04/0.04;
   H[8] = current[0]*500/0.15;
   B[9]= phi[0]*(-1)/500/0.04/0.04;
   H[9] = current[0]*500/0.15;
   B[10]= phi[0]*(-1)/500/0.04/0.04;
   H[10] = current[0]*500/0.15;
   B[11]= phi[0]*(-1)/500/0.04/0.04;
   H[11] = current[0]*500/0.15;
   B[12]= phi[0]*(-1)/500/0.04/0.04;
   H[12] = current[0]*500/0.15;
   B[13]= phi[0]*(-1)/500/0.04/0.04;
   H[13] = current[0]*500/0.15;
   B[14]= phi[0]*(-1)/500/0.04/0.04;
   H[14] = current[0]*500/0.15;
   B[15]= phi[0]*(-1)/500/0.04/0.04;
   H[15] = current[0]*500/0.15;

   double x[79], y[79], n[160];
   int k=0;
   for (int i=16;i<n1;i++){
      B[i] = phi[i]*(-1)/500/0.04/0.04;
      H[i] = current[i]*500/0.15;

      if(sw1 == 0 && B[i]>B[i-1] && B[i-1] < B[i-2] && B[i-1] < B[i-3]&& B[i-1] < B[i-4]&& B[i-1] < B[i-15]){
//         for(int j=sw2; j<i; j++){
//            sum += B[j];
//         }
//         for(int j=sw2; j<i; j++){
//            B[j] -= sum/(i-sw2);
//         }
//         sum =0;
//         n[k+1] = i;
//         k++;
//         printf("%d ", i);
         sw1 = 1;
//         sw2 = i;
      }
      if(sw1 == 1 && B[i]<B[i-1] && B[i-1] > B[i-2] && B[i-1] > B[i-3] && B[i-1] > B[i-4]&& B[i-1] > B[i-15]){
         for(int j=sw2; j<i; j++){
            sum1 += B[j];
            sum2 += H[j];
         }
         for(int j=sw2; j<i; j++){
//            B[j] -= sum1/(i-sw2);
         }
         n[k+1] = i;
         k++;
         printf("%d ", i);
         sum1 =0;
         sum2 =0;
         sw1 = 0;
         sw2 = i;
      }
   }

   TGraph *gr1 = new TGraph(n[bn]-n[bn-1],&H[n[bn-1]],&B[n[bn-1]]);
   gr1->SetTitle("Ferromagnetic Hysteresis at 2V, 0.1Hz");
   gr1->GetXaxis()->SetTitle("H(Am^{-1})");
   gr1->GetYaxis()->SetTitle("B(T)");
   gr1->SetLineColor(1);
   gr1->SetLineWidth(1);
//   gr1->GetXaxis()->SetRangeUser(-500,500);
//   gr1->GetYaxis()->SetRangeUser(-0.5,0.5);
//   TF1 *f1 = new TF1("f1", "[0]+[1]*tanh([2]*x)",-300,300);
//   f1->SetLineColor(kGray+1);
//   gr1->Fit("f1");
   c1->cd(2);
   gr1->Draw();

   double Volt[n1];
   for(int i=0; i<n1; i++)
      Volt[i] = current[i]*22;

   TGraph *gr2 = new TGraph(n[bn]-n[bn-1],&t[n[bn-1]],&Volt[n[bn-1]]);
   gr2->SetTitle("Voltage-Time at 2V, 0.1Hz");
   gr2->GetXaxis()->SetTitle("t(s)");
   gr2->GetYaxis()->SetTitle("Voltage(V)");
   gr2->SetLineColor(1);
   gr2->SetLineWidth(1);
//   gr2->GetXaxis()->SetRangeUser(-500,500);
//   gr2->GetYaxis()->SetRangeUser(-0.5,0.5);
//   TF1 *f1 = new TF1("f1", "[0]+[1]*x",0,30);
//   f1->SetLineColor(kGray+1);
//   gr1->Fit("f1");
   c1->cd(1);
   gr2->Draw();

   c1->Update();
   c1->Modified();
   return c1;
}
