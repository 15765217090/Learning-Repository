#include <iostream>
#include <type_traits>
#include <array>

void xprintf(){}
template <typename T, typename... Targs>

void xprintf(T value, Targs... Fargs)
{
std::cout << sizeof...(Fargs) << " " << value << std::endl;
xprintf(Fargs...);
}

template <typename T>
auto m_get_value(T& value, size_t index)
{
    if constexpr (std::is_array_v<T> || std::is_pointer_v<T>)
    {
        return value[index];
    }
    else
    {
        return value;
    }
}
typedef unsigned int uint32_t;
void TaskP_sleepInMsecs(uint32_t time){
    xprintf(time);
};
static void xTaskDelayMsUntil(uint32_t* const pxPreviousWakeTime, const uint32_t xTimeIncrement)
{
    uint32_t endTick = 111u;
    int sleep_time = xTimeIncrement - (endTick - *pxPreviousWakeTime);
    xprintf(sleep_time);
    TaskP_sleepInMsecs(static_cast<uint32_t>(sleep_time));
}
int main()
{

xprintf("info:", "xiaoming", "male", 35, "programmer", 169.5);
uint32_t startTick = 100u;
xTaskDelayMsUntil(&startTick,10);

std::array<int,2> a ={10,20};
int b = 7;
xprintf("a[0] is",m_get_value(a,0));
xprintf("b is",m_get_value(b,0));

return 0;
}