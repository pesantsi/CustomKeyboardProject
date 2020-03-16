#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		KC_NLCK, KC_CAPS, 
		KC_MPLY, KC_MSTP),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS),

	KEYMAP(
		KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) 
{
}

void matrix_scan_user(void) 
{
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	// If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
	uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}