#include <page_alloc.h>
#include <stddef.h>
#include <sys/mman.h>
#include <unistd.h>

#ifdef DEBUG
#include <stdio.h>
#endif

size_t PAGE_ALLOC_SIZE = 0;
bool PAGE_ALLOC_INIT = 0;

void page_alloc_init() {
  PAGE_ALLOC_SIZE = getpagesize();
  PAGE_ALLOC_INIT = true;
}

void *page_alloc(void *addr, size_t size) {
  void *data = mmap(NULL, size, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  if (data != MAP_FAILED) {
    return data;
  }

#ifdef DEBUG
  const char format[] = "alloc_page {addr: %p, size: %u}";
  char buffer[sizeof(format) + sizeof(void *) * 2];
  sprintf(buffer, format, addr, size);
  perror(buffer);
#endif

  return NULL;
}

int page_free(void *addr, size_t size) {
  if (munmap(addr, size) != -1) {
    return 0;
  }

#ifdef DEBUG
  const char format[] = "unalloc_page {addr: %p, size: %u}";
  char buffer[sizeof(format) + sizeof(void *) * 2];
  sprintf(buffer, format, addr, size);
  perror(buffer);
#endif

  return -1;
}
