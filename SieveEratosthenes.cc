bool is_prime[MAXN];
vector<int> primes;
void sieve_eratosthenes() {
	std::fill(&is_prime[0], &is_prime[0] + MAXN, true);
	is_prime[1] = false;
	for(int i = 2; i*i <= MAXN; i++){
		if(is_prime[i]){
			for(int j = i*i; j < MAXN; j += i){
				is_prime[j] = false;
			}
		}
	}
	for(int i = 2; i < MAXN; i++) {
		if(is_prime[i])
			primes.push_back(i);
	}
}
