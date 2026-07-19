export function processEngineState(payload: string): string {
  return '[SIE_RUNTIME_OK] ' + payload.toUpperCase();
}
