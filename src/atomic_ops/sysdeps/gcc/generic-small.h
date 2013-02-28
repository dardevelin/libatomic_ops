/*
 * Copyright (c) 1991-1994 by Xerox Corporation.  All rights reserved.
 * Copyright (c) 1996-1999 by Silicon Graphics.  All rights reserved.
 * Copyright (c) 2003-2011 Hewlett-Packard Development Company, L.P.
 *
 *
 * THIS MATERIAL IS PROVIDED AS IS, WITH ABSOLUTELY NO WARRANTY EXPRESSED
 * OR IMPLIED.  ANY USE IS AT YOUR OWN RISK.
 *
 * Permission is hereby granted to use or copy this program
 * for any purpose, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

AO_INLINE AO_t
AO_load(const volatile AO_t *addr)
{
  return __atomic_load_n(addr, __ATOMIC_RELAXED);
}
#define AO_HAVE_load

AO_INLINE AO_t
AO_load_acquire(const volatile AO_t *addr)
{
  return __atomic_load_n(addr, __ATOMIC_ACQUIRE);
}
#define AO_HAVE_load_acquire

/* AO_load_full is generalized using AO_load and AO_nop_full, so that   */
/* AO_load_read is defined using AO_load and AO_nop_read.               */

AO_INLINE void
AO_store(volatile AO_t *addr, AO_t value)
{
  __atomic_store_n(addr, value, __ATOMIC_RELAXED);
}
#define AO_HAVE_store

AO_INLINE void
AO_store_release(volatile AO_t *addr, AO_t value)
{
  __atomic_store_n(addr, value, __ATOMIC_RELEASE);
}
#define AO_HAVE_store_release

/* AO_store_full definition is omitted similar to AO_load_full reason.  */

AO_INLINE AO_t
AO_fetch_compare_and_swap(volatile AO_t *addr, AO_t old_val, AO_t new_val)
{
  return __sync_val_compare_and_swap(addr, old_val, new_val
                                     /* empty protection list */);
}
#define AO_HAVE_fetch_compare_and_swap

/* TODO: Add CAS _acquire/release/full primitives. */

#ifndef AO_GENERALIZE_ASM_BOOL_CAS
  AO_INLINE int
  AO_compare_and_swap(volatile AO_t *addr, AO_t old_val, AO_t new_val)
  {
    return __sync_bool_compare_and_swap(addr, old_val, new_val
                                        /* empty protection list */);
  }
# define AO_HAVE_compare_and_swap
#endif /* !AO_GENERALIZE_ASM_BOOL_CAS */

/* TODO: Add AO_char/short/int_ primitives (via template header). */
