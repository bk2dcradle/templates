template<typename T>
LL nCr(T n, T r) {
	return (((fact[n]*ifact[r])%mod)*ifact[n-r])%mod;
}
