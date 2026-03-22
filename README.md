# ESP32 NAT Router (Camper Van Edition 🚐)

A radically stripped-down, lean, and highly optimized fork of the ESP32 NAT Router.

The original project is fantastic, but it suffers from feature creep. When you live in a camper van or run a mobile off-grid network, you don't need corporate WPA2-Enterprise bridging, heavy WireGuard VPNs, or PCAP network sniffing eating up your precious ESP32 SRAM. You need absolute stability, seamless local discovery, and a rock-solid Home Assistant integration.

This fork aggressively removes unnecessary bloat to free up dynamic heap memory and flash space, while introducing practical features for IoT and mobile home automation.

## 🔪 What's Removed (The Bloat)

To achieve extreme stability and prevent Out-Of-Memory (OOM) crashes during high traffic, the following memory-hungry features have been **completely purged**:

  - **WireGuard VPN:** (Use a dedicated Pi or router for this, not an ESP32).
  - **WPA2-Enterprise:** No one is connecting to a corporate RADIUS server from a camper van.
  - **PCAP Capture:** Removed to save runtime RAM and CPU cycles.

*Result: Saved \~70KB of Flash space and drastically improved dynamic heap stability.*

## ✨ What's Added (The Good Stuff)

  - **Native mDNS Broadcasting:** - Resolves `router.local` automatically.
      - Custom UI to set Hostname and Instance Name.
      - **Dual-binding:** Broadcasts on both the AP (internal van network) and STA (upstream campsite/public network) interfaces simultaneously for seamless access.
  - **MQTT & Home Assistant UI:**
      - The original firmware had a hidden MQTT Home Assistant auto-discovery feature accessible only via CLI.
      - This fork exposes a complete, cyberpunk-styled **Web Configuration Page** for MQTT.
      - Added a crucial **Kill-Switch** for HA Auto-Discovery, giving you control over whether you want to flood your Home Assistant with entity data or just keep a quiet MQTT connection.

## ⚠️ WARNING: DO NOT USE PRE-BUILT BINARIES

**All pre-compiled `.bin` files provided in the original repository or older releases are outdated.** They still contain the bloated VPN/PCAP garbage and **DO NOT** include the custom mDNS or MQTT Web UI features introduced in this fork. To get this lean Camper Van Edition, you **MUST** build the firmware from source.

## 📸 Screenshots

<img src="https://raw.githubusercontent.com/stephen94125/esp32_nat_router/master/UI_mDNS.png">

<img src="https://raw.githubusercontent.com/stephen94125/esp32_nat_router/master/UI_MQTT.png">

## 🚀 Building and Flashing

This project uses the standard ESP-IDF (v5.x) toolchain.

```bash
# 1. Clone the repository
git clone https://github.com/YOUR_USERNAME/esp32_nat_router.git
cd esp32_nat_router

# 2. Build the firmware
idf.py build

# 3. Flash and monitor
idf.py flash monitor
```

For pre-built binaries, detailed flashing instructions, and the general architecture, please refer to the **[Original Upstream Repository by martin-ger](https://github.com/martin-ger/esp32_nat_router)**.

## ⚖️ License

This fork inherits the MIT License from the original project. The original WireGuard submodule license (though removed in this fork) and other attributions can be found in the upstream repository.
