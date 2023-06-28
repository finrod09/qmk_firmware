
QUANTUM_PAINTER_ENABLE 	= yes

RGB_MATRIX_ENABLE 		= yes 		# matrix enable turns on the white background lighting
RGB_MATRIX_LEDMAPS_ENABLED = yes 	# turn on per-key colours
RGB_MATRIX_DRIVER 		= WS2812
WS2812_DRIVER 			= vendor  	# RP2040 lyfe

# Trackball settings
POINTING_DEVICE_ENABLE 	= yes		# Flag, set to no to disable the trackball/PMW functionality
# POINTING_DEVICE_ENABLE ?= yes
ifeq ($(strip $(POINTING_DEVICE_ENABLE)), yes)
	CUSTOM_POINTING_DEVICE  = yes		# Auto-mouse layer and such
	POINTING_DEVICE_DRIVER 	= pmw3389
	DRAGSCROLL_ENABLE		= yes
endif

# Split settings
SPLIT_KEYBOARD 			= yes
# RP2040-specific split options
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.
SERIAL_DRIVER = vendor

# Encoder
ENCODER_MAP_ENABLE = yes
