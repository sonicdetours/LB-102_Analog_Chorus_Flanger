#ifndef LFO_H_
#define LFO_H_

class Lfo {
 public:

  Lfo(int32_t update_frequency) { 
    update_frequency_ = update_frequency;
  }

  void set_rate(int32_t rate) {
    rate_ = rate;
    set_interval();
  }

  void set_depth(int32_t depth) {
    depth_ = depth; 
    set_interval();
  }

  // Return LFO value (positive/negative delay in us)
  int32_t value() {
    return value_;
  }

  void Update() {
    if (value_ >= depth_) {
      direction_ = -1;  
    } 
    
    if (value_ <= depth_ * -1) {
      direction_ = 1;  
    }
     
    value_ += interval_ * direction_;
  }

 private:

  void set_interval() {
    interval_ = depth_ * 2 * rate_ / 1000 / update_frequency_;
  }

  int32_t update_frequency_;
  int32_t value_; // us
  int32_t rate_; // KHz
  int32_t depth_; // us (in either direction)
  
  int32_t interval_; 
  int8_t direction_ = 1; 
};

#endif

