#ifndef PUBLIC_INCLUDE_MYLIB_MYLIB_HPP_
#define PUBLIC_INCLUDE_MYLIB_MYLIB_HPP_

class MyLib {

 public:
  MyLib() = default;
  ~MyLib() = default;

  /** Function printing Hello in the console */
  bool sayHello();

  bool sayGoodbye();
};

#endif /* PUBLIC_INCLUDE_MYLIB_MYLIB_HPP_ */
