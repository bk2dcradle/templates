// To convert to LL,
// Change 30 to 60
int lsb(int x) {
	int res = 0;
	while(res < 30){
		if(x & (1<<res))	return res;
		res++;
	}
	assert(false);
	return res;
}
