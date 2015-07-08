#include <ccan/typesafe_cb/typesafe_cb.h>
#include <stdlib.h>

struct foo {
	int x;
};

struct bar {
	int x;
};

struct baz {
	int x;
};

struct any {
	int x;
};

struct other {
	int x;
};

static void take_any(struct any *any)
{
}

int main(int argc, char *argv[])
{
#ifdef FAIL
	struct other
#if !HAVE_TYPEOF||!HAVE_BUILTIN_CHOOSE_EXPR||!HAVE_BUILTIN_TYPES_COMPATIBLE_P
#error "Unfortunately we don't fail if cast_if_type is a noop."
#endif
#else
	struct foo
#endif
		*arg = NULL;
	take_any(cast_if_any(struct any *, arg, arg,
			     struct foo *, struct bar *, struct baz *));
	return 0;
}
