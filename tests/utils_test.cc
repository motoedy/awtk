#include "base/utils.h"
#include "gtest/gtest.h"

TEST(Utils, basic) {
  char str[32];

  ASSERT_EQ(tk_atoi("100"), 100);
  ASSERT_EQ(strcmp(tk_itoa(str, sizeof(str), tk_atoi("100")), "100"), 0);
}

static void check_buff16(uint16_t* buff, uint16_t val, uint32_t size) {
  uint32_t i = 0;
  for (i = 0; i < size; i++) {
    ASSERT_EQ(buff[i], val);
  }
}

TEST(Utils, tk_memset16) {
  uint16_t buff[32];
  uint16_t val = 0x1234;

  memset(buff, 0x00, sizeof(buff));
  tk_memset16(buff, val, 1);
  check_buff16(buff, val, 1);

  memset(buff, 0x00, sizeof(buff));
  tk_memset16(buff, val, 7);
  check_buff16(buff, val, 7);

  memset(buff, 0x00, sizeof(buff));
  tk_memset16(buff + 1, val, 10);
  check_buff16(buff + 1, val, 10);

  memset(buff, 0x00, sizeof(buff));
  tk_memset16(buff + 1, val, 11);
  check_buff16(buff + 1, val, 11);

  memset(buff, 0x00, sizeof(buff));
  tk_memset16(buff, val, 10);
  check_buff16(buff, val, 10);

  memset(buff, 0x00, sizeof(buff));
  tk_memset16(buff, val, 11);
  check_buff16(buff, val, 11);
}

static void check_buff32(uint32_t* buff, uint32_t val, uint32_t size) {
  uint32_t i = 0;
  for (i = 0; i < size; i++) {
    ASSERT_EQ(buff[i], val);
  }
}

TEST(Utils, tk_memset32) {
  uint32_t buff[32];
  uint32_t val = 0x1234;

  memset(buff, 0x00, sizeof(buff));
  tk_memset32(buff, val, 1);
  check_buff32(buff, val, 1);

  memset(buff, 0x00, sizeof(buff));
  tk_memset32(buff, val, 7);
  check_buff32(buff, val, 7);

  memset(buff, 0x00, sizeof(buff));
  tk_memset32(buff + 1, val, 10);
  check_buff32(buff + 1, val, 10);

  memset(buff, 0x00, sizeof(buff));
  tk_memset32(buff + 1, val, 11);
  check_buff32(buff + 1, val, 11);

  memset(buff, 0x00, sizeof(buff));
  tk_memset32(buff, val, 10);
  check_buff32(buff, val, 10);

  memset(buff, 0x00, sizeof(buff));
  tk_memset32(buff, val, 11);
  check_buff32(buff, val, 11);
}

TEST(Utils, tk_memcpy16) {
  uint32_t i = 0;
  uint16_t dst[100];
  uint16_t src[100];

  tk_memset16(src, 0x1234, ARRAY_SIZE(src));
  for(i = 1; i < ARRAY_SIZE(src); i++) {
    tk_memcpy16(dst, src, i);
    ASSERT_EQ(memcmp(dst, src, i * 2), 0);
  }
}

TEST(Utils, tk_memcpy32) {
  uint32_t i = 0;
  uint32_t dst[100];
  uint32_t src[100];

  tk_memset32(src, 0x12345678, ARRAY_SIZE(src));
  for(i = 1; i < ARRAY_SIZE(src); i++) {
    tk_memcpy32(dst, src, i);
    ASSERT_EQ(memcmp(dst, src, i * 4), 0);
  }
}

