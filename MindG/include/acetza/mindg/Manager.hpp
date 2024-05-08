namespace acetza::mindg {
class Manager {
 public:
  static Manager& Instance() {
    static Manager instance;
    return instance;
  }
  ~Manager() = default;
  Manager(Manager&&) = delete;
  Manager& operator=(Manager&&) = delete;
  Manager(Manager const&) = delete;
  void operator=(Manager const&) = delete;

 private:
  Manager() = default;
};
}  // namespace acetza::mindg