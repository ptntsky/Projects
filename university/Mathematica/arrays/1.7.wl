A = {{5,0,-6}, {-4,3,2},{4,-8,3}};
spysok = Flatten[A];
psp = Select[spysok, #>0&];
psum = Total[psp];
pcnt= Length[psp];
nsp = Select[spysok, #<0&];
nsum = Total[nsp];
ncnt = Length[nsp];
Print[psum ]
Print[pcnt]
Print[nsum]
Print[ncnt]
