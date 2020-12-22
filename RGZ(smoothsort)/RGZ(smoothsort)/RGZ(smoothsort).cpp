#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <chrono>
#include <algorithm>
#define N 5
#define K 5000
using namespace std;


typedef int value_t;


static int cmp(value_t a, value_t b) {
	if (a > b)return 4;
	else if (a < b)return -4;
	else return 0;
}



struct state {
	value_t* a;
	size_t q, r, p, b, c, r1, b1, c1;
};

#if __STDC_VERSION__ < 199901L
#	define inline 
#endif

static inline void up(size_t* a, size_t* b) {
	size_t tmp;

	tmp = *a;
	*a += *b + 1;
	*b = tmp;
}

static inline void down(size_t* a, size_t* b) {
	size_t tmp;

	tmp = *b;
	*b = *a - *b - 1;
	*a = tmp;
}

static void sift(struct state* s) {
	size_t r0, r2;
	value_t tmp;

	r0 = s->r1;
	tmp = s->a[r0];

	while (s->b1 > 2) {
		r2 = s->r1 - s->b1 + s->c1;

		if (cmp(s->a[s->r1 - 1], s->a[r2]) >= 0) {
			r2 = s->r1 - 1;

			down(&s->b1, &s->c1);
		}

		if (cmp(s->a[r2], tmp) < 0) {
			s->b1 = 1;
		}
		else {
			s->a[s->r1] = s->a[r2];
			s->r1 = r2;

			down(&s->b1, &s->c1);
		}
	}

	if (s->r1 - r0 > 0) {
		s->a[s->r1] = tmp;
	}
}

static void trinkle(struct state* s) {
	size_t p1, r0, r2, r3;
	value_t tmp;

	p1 = s->p;
	s->b1 = s->b;
	s->c1 = s->c;
	r0 = s->r1;
	tmp = s->a[r0];

	while (p1 > 0) {
		while ((p1 & 1) == 0) {
			p1 >>= 1;

			up(&s->b1, &s->c1);
		}

		r3 = s->r1 - s->b1;

		if (p1 == 1 || cmp(s->a[r3], tmp) < 0) {
			p1 = 0;
		}
		else {
			p1--;

			if (s->b1 == 1) {
				s->a[s->r1] = s->a[r3];
				s->r1 = r3;
			}
			else if (s->b1 >= 3) {
				r2 = s->r1 - s->b1 + s->c1;

				if (cmp(s->a[s->r1 - 1], s->a[r2]) >= 0) {
					r2 = s->r1 - 1;

					down(&s->b1, &s->c1);

					p1 <<= 1;
				}

				if (cmp(s->a[r2], s->a[r3]) < 0) {
					s->a[s->r1] = s->a[r3];
					s->r1 = r3;
				}
				else {
					s->a[s->r1] = s->a[r2];
					s->r1 = r2;

					down(&s->b1, &s->c1);

					p1 = 0;
				}
			}
		}
	}

	if (s->r1 - r0 != 0) {
		s->a[s->r1] = tmp;
	}

	sift(s);
}

static void semitrinkle(struct state* s) {
	value_t tmp;

	s->r1 = s->r - s->c;

	if (cmp(s->a[s->r1], s->a[s->r]) >= 0) {
		tmp = s->a[s->r];
		s->a[s->r] = s->a[s->r1];
		s->a[s->r1] = tmp;

		trinkle(s);
	}
}

void smoothsort(value_t* a, size_t n) {
	struct state s;
	size_t tmp;

	s.a = a;
	s.r = 0;
	s.p = s.b = s.c = 1;

	
	for (s.q = 1; s.q < n; s.q++) {
		s.r1 = s.r;
		if ((s.p & 7) == 3) {
			s.b1 = s.b;
			s.c1 = s.c;
			sift(&s);

			s.p = (s.p + 1) >> 2;

			
			tmp = s.b + s.c + 1;
			s.b += tmp + 1;
			s.c = tmp;
		}
		else if ((s.p & 3) == 1) {
			if (s.q + s.c < n) {
				s.b1 = s.b;
				s.c1 = s.c;

				sift(&s);
			}
			else {
				trinkle(&s);
			}

			do {
				down(&s.b, &s.c);
				s.p <<= 1;
			} while (s.b > 1);

			s.p++;
		}

		s.r++;
	}

	s.r1 = s.r;
	trinkle(&s);

	
	while (s.q-- > 1) {
		if (s.b == 1) {
			s.r--;
			s.p--;

			while ((s.p & 1) == 0) {
				s.p >>= 1;

				up(&s.b, &s.c);
			}
		}
		else if (s.b > 2) {
			s.p--;
			s.r = s.r - s.b + s.c;

			if (s.p > 0) {
				semitrinkle(&s);
			}

			down(&s.b, &s.c);

			s.p = (s.p << 1) + 1;
			s.r += s.c;
			semitrinkle(&s);

			down(&s.b, &s.c);

			s.p = (s.p << 1) + 1;
		}

	}

}



int main() {
	srand(time(0));
	int arr[N + 10];
	int* a;
	a = arr;
	double avg_dur = 0, dur[K + 10];
	for (int i = 0; i < N; ++i)
		a[i] = rand() % 100 + 1;
	cout << "Primary array:" << endl;

	sort(a, a + N);
	//reverse(a, a + N);

	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";
	for (int i = 0; i < K; ++i) {
		auto start = chrono::high_resolution_clock::now();
		smoothsort(a, N);
		auto end = std::chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;

		dur[i] = duration.count();
	}
	sort(dur, dur + K);
	for (int i = 100; i < K - 100; ++i)
		if (dur[i] > 0)avg_dur += dur[i];
	cout << endl << "Sorted array: " << endl;
	for (int i = 0; i < N; i++)
		cout << a[i] << " ";
	for (int i = 0; i < K; ++i)
		cout << "Duration " << i + 1 << ": " << dur[i] << "s" << endl;
	cout << endl << "Average duration: " << avg_dur / (K - 201) << "s";
}