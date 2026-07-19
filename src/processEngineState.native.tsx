import PlaystationUiBridge from './NativePlaystationUiBridge';

export function processEngineState(payload: string): string {
  return PlaystationUiBridge.processEngineState(payload);
}
