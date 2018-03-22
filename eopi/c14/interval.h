#ifndef _INTERVAL_H_
#define _INTERVAL_H_
struct event {
    int s, e;
    event( int s, int e ) : s( s ), e ( e ) {}
    bool operator<(const event & c) const {
        return s <= c.s;
    }
};
struct marker {
    int  t;
    bool s;
    marker( int t, bool s ) : t( t ), s( s ) {}
    bool operator<(const marker & m) const {
        return t != m.t ? t < m.t : ( s && !m.s );
    }
};
#endif
