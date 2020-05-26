#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


double poisson(double mu, int k) {
    
    double mu_k = pow(mu, k);
    double e_mu = exp(-mu);
    double k_fac = tgamma(k+1);

    return (mu_k*e_mu/k_fac);
}

int main(){
  
  using namespace std;
  
  int n_i;
  double mu = 3.11538;
  double li = 1;
  double l = 1;
  
  ifstream fin("datensumme.txt");
  ofstream like("likelihood.txt");
  ofstream like2("likelihood2.txt");
  
  vector<int> daten;

  for(int i = 0; i < 234; i++){
    
    fin >> n_i;
    daten.push_back(n_i);
  
  }

  for(int k : daten){
    
    double li = poisson(mu, k);
    
    l *= li;
  }

  cout << l << endl;

  for(double j = 0; j < 6;){
    
    double h = 1;
    
      for(int n : daten){
      
        double hi = poisson(j, n);
      
        h *= hi;
      }

    like << j <<" "<< h << endl;
    like2 << h << endl;
    j += 0.01;
  }

fin.close();
like.close();
like2.close();
}