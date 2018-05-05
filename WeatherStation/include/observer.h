#ifndef _06HW_INCLUDE_OBSERVER_
#define _06HW_INCLUDE_OBSERVER_

namespace csce240 {

class Observer {
 public:
  virtual ~Observer() = 0;

  virtual void Update() = 0;
};

}  // namespace csce240

#endif
