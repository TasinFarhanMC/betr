#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>

extern size_t PAGE_ALLOC_SIZE;
extern bool PAGE_ALLOC_INIT;

void page_alloc_init();
void *page_alloc(void *addr, size_t size);
int page_free(void *addr, size_t size);

#ifdef __cplusplus
}
#endif
