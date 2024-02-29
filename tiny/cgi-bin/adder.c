/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void)
{
  char *buf, *p;
  char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
  int n1 = 0, n2 = 0;

  /* Extract the two arguments */
  /* 2개 인수 추출 */
  // 웹 서버는 요청 정보를 환경 변수를 통해 CGI 프로그램에 전달
  // 클라이언트가 전달한 쿼리 문자열을 받아오기
  if ((buf = getenv("QUERY_STRING")) != NULL)
  {
    // '&' 문자 위치 저장
    p = strchr(buf, '&');
    // '&' 문자가 있던 자리에 널 문자('\0')를 삽입
    *p = '\0';
    // '&' 문자 이전까지의 문자
    strcpy(arg1, buf);
    // '&' 문자 이후의 문자
    strcpy(arg2, p + 1);
    // 문자열을 정수로 변환
    n1 = atoi(arg1);
    n2 = atoi(arg2);
  }

  /* 응답할 HTML body 생성 */
  sprintf(content, "QUERY_STRING=%s", buf);
  sprintf(content, "Welcome to add.com : ");
  sprintf(content, "%sThe Internet addition portal.\r\n<p>", content);
  sprintf(content, "%sThe answer is : %d + %d = %d\r\n<p>",
          content, n1, n2, n1 + n2);
  sprintf(content, "%sThanks for visiting!\r\n", content);

  /* HTTP 응답 생성 */
  printf("Connection : close\r\n");
  printf("Content-length : %d\r\n", (int)strlen(content));
  printf("Content-type : text/html\r\n\r\n");
  printf("%s", content);
  fflush(stdout);

  exit(0);
}
/* $end adder */