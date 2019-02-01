REP(i,Z) magic[i] = i;
REP1(i,1,Z) for(int j=i*2;j<Z;j+=i) magic[j]-=magic[i];

magic[1] = 1;
REP1(i,1,Z) for(int j = 2*i;j<Z;j+=i) magic[j] -= magic[i];
