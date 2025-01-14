#pragma once

namespace hooks {
  void initialize();
}

namespace hooks::present {
  inline ID3D11Device* device;
  inline ID3D11DeviceContext* context;
  inline ID3D11RenderTargetView* render_target;

  inline LARGE_INTEGER performance_counter;
  inline LARGE_INTEGER performance_frequency;
  inline int frames = 0;

  inline std::once_flag flag;

  using function_type = long(__stdcall*)(IDXGISwapChain*, unsigned int, unsigned int);
  inline function_type original;

  long __stdcall hook(IDXGISwapChain* swap_chain, unsigned int sync_interval, unsigned int flags);
}

namespace hooks::wndproc {
  inline HWND window;

  using function_type = long long(__stdcall*)(HWND, unsigned int, unsigned long long, long long);
  inline function_type original;

  long long __stdcall hook(HWND window, unsigned int message, unsigned long long wparam, long long lparam);
}

namespace hooks::set_field_of_view {
  using function_type = void(*)(void*, float, void*);
  inline function_type original;

  void hook(void* _this, float value, void* method_info);
}