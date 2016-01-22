#include <hk/log.h>

int main(int argc, char* argv[]) {
  hklog(HK_INFO, "everything is fine%s\n", "!");
  hklog(HK_DEBUG, "just debugging%s\n", "...");
  hklog(HK_WARN, "i'm warning you%s\n", "...!");
  hklog(HK_ERR, "error%s\n", "!");
  hklog(HK_FATAL, "fatal%s\n", "!!");

  return 0;
}
