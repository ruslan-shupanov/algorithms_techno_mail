#include <stdio.h>
#include <vector>
//#include <pair>
#include <utility>

struct huf {
    int code; //'a'
    huf *c[2];
    int freq;
    huf(int _code, int _freq) : freq(_freq), code(_code) {c[0] = c[1] = NULL;}
};

struct phuf {
    huf *d;

};

bool operator < (phuf const &l, phuf const &r) {
    return l.d->freq > r.d->freq;
}

struct bhnode {
    int priority;
//    int value;

};

huf *gen_huf_tree(vector<pair <int, int> > const &inp) {
    priority_queue<phuf> pq;
    for (auto const &e : inp) {
        phuf t{new huf(e.first, e.secons)};
        pq.push(t);
    }
    while (pq.size() > 1) {
        auto a = pq.top(), pq.pop();
        auto b = pq.top(), pq.pop();
        huf *h = new huf(-1, a.d->freq +b.d->freq);
        h->c[0] = a.d; h->c[1] = b.d;
        phuf t(h); pq.push(t);
    }
    auto z = pq.top; pq.pop();
    return z.d;
}

// s;
//walk(root, v, " ");
void walk(huf *t, vector<string> &v, string s) {
    if (t->c[0] != NULL) {
        walk(t->c[0], v, s + "0");
    }
    if (t->c[1] != NULL) {
        walk(t->c[1], v, s+"1");
    }
    if (t->code >= 0) {
        v[t->code] = s;
    }

}


class priority_queue {
public:
    priority_queue(int MAX) {
        body = new bhnode[maxsize = MAX+1];
        numnodes = 0;
    }

    ~priority_queue() {
        delete [] body;
    }

    int insert(bhnode const &node) {
        if (numnodes > maxsize) {
            return -1; // или расширяем.
        }
        body[++numnodes] = node;
        for (int i = numnodes; i > 1 &&
                               body[i].priority > body[i/2].priority;
             i /= 2) {
            swap(i, i/2);
        }
        return 0;
    }

    bhnode *fetchMin() {
        return numnodes == 0? NULL : body + 1;
    }

    int removeMin() {
        if (numnodes == 0) return -1;
        body[1] = body[numnodes--];
        heapify(1);
        return 0;
    }

    int increasePriority(int index, int priority) {
        if (body[index].priority >= priority)
            return -1;
        for (body[index].priority = priority;
             index > 1 && body[index].priority > body[index/2].priority;
             index /= 2) {
            swap(index, index/2);
        }
        return index;
    }

    void print() {
        printf("max=%d size=%d elems={ ", maxsize, numnodes);
        for (int i = 0; i < numnodes; i++) {
            printf("%d ", body[i].priority);
        }
        printf("}\n");
    }
private:
    void heapify(int index) {
        for (;;) {
            int left = index + index; int right = left + 1;
            // Кто больше, [index], [left], [right]?
            int largest = index;
            if (left <= numnodes &&
                body[left].priority > body[index].priority)
                largest = left;
            if (right <= numnodes &&
                body[right].priority > body[largest].priority)
                largest = right;
            if (largest == index) break;
            swap(index, largest);
            index = largest;
        }
    }

    void swap(int n1, int n2) {
        bhnode t = body[n1];
        body[n1] = body[n2];
        body[n2] = t;
    }
    bhnode *body;
    int numnodes;
    int maxsize;
};
