This is a comprehensive roadmap to the advanced mathematics required for high-level Competitive Programming (AtCoder E-G, Codeforces Div 1). Since you want to build your own library, I have marked items with **[Template]** if they are standard algorithms you should implement and store.

The roadmap is divided into 4 Phases, moving from "Fundamental Number Theory" to "Abstract & heavy-duty Math."

---

### Phase 1: Number Theory & Modular Arithmetic

*The bread and butter of competitive programming. You cannot skip these.*

1. **Extended Euclidean Algorithm (ExGCD)** **[Template]**
* **What:** Finds  for . Used to find modular inverses when modulo is not prime.
* **Application:** Solving linear Diophantine equations.


2. **Modular Inverse & Fermat's Little Theorem** **[Template]**
* **What:** Calculating  for prime .
* **Application:** Essential for combinatorics (calculating ).


3. **Sieve of Eratosthenes & Linear Sieve** **[Template]**
* **What:** Finding primes up to  in .
* **Application:** Precomputing prime factors for many queries.


4. **Chinese Remainder Theorem (CRT)** **[Template]**
* **What:** Solves systems of congruences ().
* **Application:** Combining results modulo different primes (often to handle huge numbers).


5. **Miller-Rabin & Pollard’s Rho** **[Template]**
* **What:** Primality test and Integer factorization for 64-bit numbers ().
* **Application:** "Is  prime?" or "Find factors of " when  is too big for a sieve.



**📚 Resources:**

* [CP-Algorithms: Number Theory](https://cp-algorithms.com/algebra/prime-sieve-linear.html)
* [KACTL Number Theory Templates](https://www.google.com/search?q=https://github.com/kth-competitive-programming/kactl/tree/main/content/number-theory)

---

### Phase 2: Combinatorics & Linear Algebra

*Common in AtCoder E/F problems.*

1. **Binomial Coefficients () & Lucas Theorem** **[Template]**
* **What:** Precompute factorials to answer  queries in . Lucas theorem handles  where  is small.


2. **Matrix Exponentiation** **[Template]**
* **What:** Computing  in .
* **Application:** Solving Linear Recurrences (like Fibonacci for huge ), counting paths in graphs of length .


3. **Gaussian Elimination & XOR Basis** **[Template]**
* **What:** Solving systems of linear equations or finding the basis of a set of integers under XOR.
* **Application:** "Find the maximum XOR subset" or "Number of ways to XOR to 0."


4. **Inclusion-Exclusion Principle**
* **What:** 
* **Application:** Counting problems where "at least one condition fails" is easier to calculate.


5. **Cayley's Formula & Matrix Tree Theorem**
* **What:** Counting spanning trees.
* **Application:** Graph theory problems that ask for "number of ways to connect...".



**📚 Resources:**

* [CP-Algorithms: Linear Algebra](https://cp-algorithms.com/linear_algebra/linear-system-gauss.html)
* [Codeforces Blog: XOR Basis](https://codeforces.com/blog/entry/68953)

---

### Phase 3: Polynomials & Series (The "Heavy" Stuff)

*Essential for AtCoder F/G. This is where ratings jump from 1800 to 2400.*

1. **FFT / NTT (Fast Fourier Transform)** **[Template]**
* **What:** Multiply two polynomials of degree  in .
* **Application:** Convolution. "Find number of pairs  such that  for all ."


2. **Generating Functions**
* **What:** Representing sequences as polynomials.
* **Application:** Solves complex counting problems (partitioning numbers, counting bracket sequences) by turning them into polynomial multiplication.


3. **Lagrange Interpolation** **[Template]**
* **What:** Given  points, find  for the unique degree  polynomial passing through them.
* **Application:** Sum of powers , or finding the -th term of a sequence when  is huge ().


4. **Formal Power Series Operations** **[Template]**
* **What:** Polynomial Inversion, Log, Exp, Sqrt in .
* **Application:** Advanced counting problems (e.g., counting connected graphs of size ).



**📚 Resources:**

* [CP-Algorithms: FFT](https://cp-algorithms.com/algebra/fft.html)
* [AtCoder Library (Convolution)](https://www.google.com/search?q=https://atcoder.jp/home/acl)

---

### Phase 4: Geometry & Functions

*Geometry is template-heavy. Implementing these on-the-fly is suicide.*

1. **Point & Vector Class** **[Template]**
* **What:** Dot product, Cross product, distance, rotation.
* **Application:** Foundation for all geometry.


2. **Convex Hull (Monotone Chain)** **[Template]**
* **What:** Finding the smallest polygon enclosing a set of points.
* **Application:** Geometry problems, optimization.


3. **Floor Sum / Euclidean Like** **[Template]**
* **What:** The algorithm we discussed ().
* **Application:** Integer geometry, lattice points.


4. **Slope Trick** **[Template]**
* **What:** Maintaining a convex function using two priority queues.
* **Application:** DP optimization where the transition involves adding convex functions (e.g., ).


5. **Möbius Inversion**
* **What:** .
* **Application:** Number theory problems involving GCDs (e.g., "Count pairs with ").



**📚 Resources:**

* [C++ Geometry Template (complex numbers)](https://codeforces.com/blog/entry/22175)
* [Slope Trick Guide](https://codeforces.com/blog/entry/77298)

---

### Phase 5: Game Theory (Niche but Standard)

1. **Nim Game & Sprague-Grundy Theorem**
* **What:** Reducing impartial games to XOR sums (Nim-values).
* **Application:** "Who wins this game?" problems.



---

### How to Practice & Build

1. **Don't build everything at once.** Start with Phase 1.
2. **Solve a problem first, then template it.** Do not copy-paste a template you haven't used to solve at least one problem.
3. **Verification:** Submit your templates to **[Library Checker](https://judge.yosupo.jp/)**. This is a judge specifically designed to test your templates (e.g., it has a problem just for "Matrix Exponentiation" or "Convolution").

**Recommended Roadmap for you:**

1. Implement `ModularInt` struct (auto modulo arithmetic).
2. Implement `nCr` (Combinatorics).
3. Implement `ExGCD` and `floor_sum`.
4. Implement `DSU` and `Fenwick Tree` (if you haven't).
5. Tackle `NTT` only when you hit a convolution problem.