#include<iostream>
#include<vector>
#include<cmath>

double PI	=	3.141592653589793238;

std::vector<double> get_Standard_Chebyshev_Nodes(int nNodes) {
	std::vector<double> xNodes;
	for (int j=-nNodes+1; j<nNodes; j+=2) {
		xNodes.push_back(sin(0.5*PI*j/nNodes));
	}
	return xNodes;
}

std::vector<double> get_Scaled_Chebyshev_Nodes(int nNodes, double a, double b) {
	std::vector<double> xNodes;
	double center	=	0.5*(a+b);
	double radius	=	0.5*(b-a);
	for (int j=-nNodes+1; j<nNodes; j+=2) {
		xNodes.push_back(center+radius*sin(0.5*PI*j/nNodes));
	}
	return xNodes;
}

std::vector<double> get_Chebyshev_Polynomial(std::vector<double> x, int nPoly) {
	std::vector<double> T;
	int N	=	x.size();
	for (int j=0; j<N; ++j) {
		T.push_back(cos(nPoly*acos(x[j])));
	}
	return T;
}

std::vector<std::vector<double> > get_Chebyshev_Polynomials(std::vector<double> x, int nPoly) {
	std::vector<std::vector<double> > T;
	int N	=	x.size();
	if (nPoly > -1) {
		std::vector<double> temp;
		for (int j=0; j<N; ++j) {
			temp.push_back(1.0);
		}
		T.push_back(temp);
	}
	if (nPoly > 0) {
		T.push_back(x);
	}
	if (nPoly > 1) {
		for (int j=2; j<=nPoly; ++j) {
			std::vector<double> temp;
			for (int k=0; k<N; ++k) {
				temp.push_back(2.0*x[k]*T[j-1][k]-T[j-2][k]);
			}
			T.push_back(temp);
		}
	}
	return T;
}