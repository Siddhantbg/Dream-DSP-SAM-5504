# SAM5504 Eval Board GUI

JUCE 8.0.12 control application for the SAM5504 Dream DSP evaluation board firmware in the sibling `dreamdesigner-DSP96khz_Optimized-master` folder.

## Open in Visual Studio 2022 / 2026

1. Install JUCE at `E:\Atomik Audio\juce-8.0.12-windows\JUCE` (or re-save `SAM5504EvalGUI.jucer` in Projucer with your path).
2. Open **`Builds/VisualStudio2026/SAM5504EvalGUI.sln`** (or `Builds/VisualStudio2022/` if you have v143 tools).
3. Set **SAM5504EvalGUI** as startup project, **Debug | x64**, press **F5**.

Regenerate projects after editing the `.jucer`:

```text
Projucer.exe --resave SAM5504EvalGUI.jucer --fix-missing-dependencies
```

## Hardware

1. Flash `dreamdesigner-DSP96khz_Optimized-master/build/*.hex` to the 5504-DK.
2. Connect USB; select the Dream USB MIDI port in the app and click **Connect MIDI**.
3. Move sliders — parameters are sent as NRPN/SysEx to the board; host WASAPI preview plays a test tone.

## Layout

- **Input** — L/R gain, mute, EQ and crossover graphs
- **L Sub / L Mid / R Sub / R Mid** — per-DSP controls matching firmware MIDI channels 0–3
