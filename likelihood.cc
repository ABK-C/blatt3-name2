#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define n_dof 233

double poisson(double mu, int k) {
    
    double mu_k = pow(mu, k);
    double e_mu = exp(-mu);
    double k_fac = tgamma(k+1);

    return (mu_k*e_mu/k_fac);
}

int main() {

using namespace std;

int n_i;
double mu = 3.11538;
double l = 1;
double li = 1;
double nges = 1;
int i;
    
ifstream fin("datensumme.txt");
ofstream like("likelihood.txt");
ofstream nll("nll.txt");
ofstream delta("deltanll.txt");

vector<int> daten;
    
    
    
for(int i = 0 ; i < 234 ; ++i) {
        
  fin >> n_i;
  daten.push_back(n_i);
    
}

for(int k : daten) {
    
  double li = poisson(mu, k);
    
  l *= li;

  double m = poisson(k, k);
    
  nges *= m;
    
} 
    
cout << l << endl;

for (double j = 0; j < 6; j+=0.01) {
  
  double l2 = 1;
      
  for(int k : daten) {    
    
    double li2 = poisson(j, k);
    l2 *= li2;  
  
  }

like << j << " " << l2 << endl;
      
nll << j << " " << (-2)*log(l2) << endl;

delta << j << " " << (-2)*log(l2)-((-2)*log(mu)) << endl;
      
}

double lam = l/nges;

cout << lam << endl;
cout << (-2)*log(lam) << endl;


double z = ((-2)*log(lam) - n_dof) / sqrt(2*n_dof);
cout << z << endl;

fin.close();
like.close();
nll.close();
delta.close();
}