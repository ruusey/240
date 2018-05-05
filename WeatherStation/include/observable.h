#ifndef _06HW_INCLUDE_OBSERVABLE_
#define _06HW_INCLUDE_OBSERVABLE_

#include "observer.h"

namespace csce240 {

class Observable {
 public:
  virtual ~Observable();

  void Add(Observer* observer);
  void Delete(Observer* observer);
  void Notify();

};

}  // namespace csce240
#endif
