import PlaystationUiBridge from './NativePlaystationUiBridge';

export function multiply(a: number, b: number): number {
  return PlaystationUiBridge.multiply(a, b);
}
