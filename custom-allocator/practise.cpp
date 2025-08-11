#include <iostream>
#include <memory>
#include <limits>

template <typename T>
class LimitedAllocator {
public:
    using value_type = T;

    LimitedAllocator() noexcept = default;

    template <typename U>
    LimitedAllocator(const LimitedAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        if (allocated_count + n > max_allocations) {
            std::cerr << "[Allocator] Limit reached! Cannot allocate more.\n";
            throw std::bad_alloc();
        }
        allocated_count += n;
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) noexcept {
        allocated_count -= n;
        ::operator delete(p);
    }

    template <typename U>
    struct rebind {
        using other = LimitedAllocator<U>;
    };

private:
    static inline std::size_t allocated_count = 0;
    static constexpr std::size_t max_allocations = 10;
};

// Equality comparison required for allocators
template <typename T, typename U>
bool operator==(const LimitedAllocator<T>&, const LimitedAllocator<U>&) { return true; }

template <typename T, typename U>
bool operator!=(const LimitedAllocator<T>&, const LimitedAllocator<U>&) { return false; }

// Example usage
#include <vector>

int main() {
    try {
        std::vector<int, LimitedAllocator<int>> v;
        for (int i = 0; i < 15; ++i) {
            v.push_back(i);
            std::cout << "Pushed: " << i << "\n";
        }
    } catch (const std::bad_alloc&) {
        std::cout << "Allocation failed after reaching the limit.\n";
    }
}
