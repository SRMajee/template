// ∑ (subset_sum)^2 = 2^(c-1)*Q + 2^(c-2)*S^2
/*
 * c = count
 * S = sum
 * Q = sum of square
 */
inline ll subset_sum(ll c, ll S, ll Q)
{
    return add(mul(binpow(2, c - 1), Q), mul(binpow(2, c - 2), binpow(S, 2)));
}