#pragma once


class HostTimerDispatcher
{
public:
	HostTimerDispatcher();
	~HostTimerDispatcher();

	inline void setWindow(HWND hWnd) { m_hWnd = hWnd; }


	unsigned setInterval(unsigned delay, IDispatch * pDisp);
	unsigned setTimeout(unsigned delay, IDispatch * pDisp);
	void kill(unsigned timerID);
	// main thread only
	void invoke(UINT timerId);
	void reset();

private:
	void addTimerMap(unsigned timerID, IDispatch * pDisp);

	static void CALLBACK g_timer_proc(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

	unsigned m_accuracy;
	HWND m_hWnd;

	typedef pfc::map_t<UINT, IDispatch *> TimerDispatchMap;
	TimerDispatchMap m_timerDispatchMap;
};
