// File: hardware/xiaomi/interfaces/touchfeature/aidl/vendor/xiaomi/hw/touchfeature/ITouchFeature.aidl
package vendor.xiaomi.hw.touchfeature;

@VintfStability // <-- ADD THIS ANNOTATION
interface ITouchFeature {
    /**
     * Sets a touch mode feature.
     *
     * @param displayId The display to apply the mode on.
     * @param mode The feature mode to set (e.g., DT2W mode is 14).
     * @param value The value to set for the mode (e.g., 1 for on, 0 for off).
     */
    void setTouchMode(int displayId, int mode, int value);

    /**
     * Sets an edge mode feature.
     * This is for compatibility with other features, you may not need to implement it.
     */
    void setEdgeMode(int displayId, int mode, in int[] value, int len);
}
