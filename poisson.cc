#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#define N 234
/*#define double mu 3.11538 ???? */


double poisson(double mu, int k) {
    
    double mu_k = pow(mu, k);
    double e_mu = exp(-mu);
    double k_fac = tgamma(k+1);

    return (mu_k*e_mu/k_fac);
}

int main() {
    
    using namespace std;

    int n_i;
    int j = 0;
    double mu = 3.11538;
    double p;
    
    ifstream fin("datensumme.txt");
    ofstream hist("hist.txt");
    ofstream histpoi("histpoi.txt");
    
    
    
    vector<int> zaehler(11);
    
    for(int i = 0 ; i < 234 ; ++i) {
      fin >> n_i;
      zaehler[n_i] +=1;
        
    }
    
    for(vector<int>::const_iterator h = zaehler.begin(); h != zaehler.end(); ++h)
    {
      
      p = poisson(mu,j);

      hist << j << " " << *h << endl;
      histpoi << j << " "<< *h << " " << N*p << endl;
      
      ++j;
    }

    fin.close();
    hist.close();
    histpoi.close();
}