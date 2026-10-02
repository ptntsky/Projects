n = 13;
z = {{n+4, n/2, Mod[n,2], 0}, {n/4, n+3, Mod[n,3], Mod[n,4]}, {Mod[n,2], Mod[n,3], n+2, n/6}, {0, Mod[n,4], n/4, n+1}}; (* 1 *)
MatrixForm[z]TableForm[z](* 2 *) 
pos = Position[z,0];
Do[
z = Insert[Delete[z,p],p[[1]], p], {p,pos}];
MatrixForm[z]
Det[z]
Transpose[z]
Eigenvalues[N[z]]
q = Join[z[[1]], z[[All, 3]]]
q = Delete[q, {{3}, {8}}]
union = Join[Flatten[z] , q]
sort = Sort[union]
